// Copyright Microsoft. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and / or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#include "v8.h"
#include "v8chakra.h"
#include "jsrtutils.h"

namespace v8 {

Template::Template() {
}

void Template::Set(
    Handle<String> name, Handle<Data> value, PropertyAttribute attributes) {
  void* externalData;
  if (JsGetExternalData(this, &externalData) != JsNoError) {
    return;
  }

  TemplateData *templateData = reinterpret_cast<TemplateData*>(externalData);
  Object* properties = templateData->EnsureProperties();
  if (properties != nullptr) {
    properties->ForceSet(name, value.As<Value>(), attributes);
  }
}
void Template::Set(Isolate* isolate, const char* name, Handle<FunctionTemplate> value) {
	Set(v8::String::NewFromUtf8(isolate, name), value->GetFunction());
}
void Template::Set(Isolate* isolate, const char* name, Handle<ObjectTemplate> value) {
	Set(v8::String::NewFromUtf8(isolate, name), value->NewInstance());
}

}  // namespace v8
