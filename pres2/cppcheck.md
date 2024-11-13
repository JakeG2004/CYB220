# CPPCheck

## File input
* For one file:
```
cppcheck <filename>
```

* For several files
```
cppcheck <path>
```

* Filter files
```
--file-filer=<str>
```

* Excluding a file
```
cppcheck -i<file / path to ignore>
```

## Severities
* Error
	* either undefined behavior or other error such as memory or resource leak
* warning
	* When code is executed there may be undefined behavior
* style
	* Stylistic issues, unused functions, redundant code, constness, operator precedence, possible mistakes
* performance
	* run time performance suggestions based on common knowledge
* portability
	* portability warnings
* information
	* configuration problems
