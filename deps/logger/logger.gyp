{
  'targets': [
    {
      'target_name': 'logger',
      'type': 'static_library',
      'include_dirs': [ 
	    './include',
		'../../src',
		'../chakrashim/include',
	  ],
      'sources': [ 
        'include/ILogger.h',
        'include/logger_wrap.h',
        'include/node_logger.h',
	    'src/logger_wrap.cpp', 
	    'src/node_logger.cpp', 
	  ],
    },
  ]
}
