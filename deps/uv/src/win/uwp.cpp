#include <windows.storage.h>
#include <wrl/client.h>
#include <wrl/wrappers/corewrappers.h>

extern "C" HRESULT GetLocalFolderPath(WCHAR* path) {
  HRESULT hr;
  Microsoft::WRL::ComPtr<ABI::Windows::Storage::IApplicationDataStatics> applicationDataStatics;

  hr = Windows::Foundation::GetActivationFactory(Microsoft::WRL::Wrappers::HStringReference(RuntimeClass_Windows_Storage_ApplicationData).Get(), &applicationDataStatics);
  if (FAILED(hr)) {
      return hr;
  }

  Microsoft::WRL::ComPtr<ABI::Windows::Storage::IApplicationData> applicationData;
  hr = applicationDataStatics->get_Current(&applicationData);
  if (FAILED(hr)) {
      return hr;
  }

  Microsoft::WRL::ComPtr<ABI::Windows::Storage::IStorageFolder> storageFolder;
  hr = applicationData->get_LocalFolder(&storageFolder);
  if (FAILED(hr)) {
      return hr;
  }

  Microsoft::WRL::ComPtr<ABI::Windows::Storage::IStorageItem> storageItem;
  hr = storageFolder.As(&storageItem);
  if (FAILED(hr)) {
      return hr;
  }

  HSTRING folderName;
  hr = storageItem->get_Path(&folderName);
  if (FAILED(hr)) {
      return hr;
  }

  UINT32 length;
  PCWSTR value = WindowsGetStringRawBuffer(folderName, &length);
  wcsncpy_s(path, MAX_PATH, value, _TRUNCATE);
  WindowsDeleteString(folderName);
  return S_OK;
}
