# filecrud
CRUD operations in a file

This is using:

1) cmake-js
2) clang-format (lint rules same as https://github.com/nodejs/node-addon-api/blob/master/.clang-format)
3) cmake with basic configuration on CMakeLists.txt
4) package.json to automate build, run and lint with `npm it`

```console
npm it
```

Interesting part of the c code are:

- The `__fpurge` from `stdio_ext.h` to clean the
buffer and to have a consistent menu running in the loop.

- The `fputc` and `fgetc` from `stdio.h` to write and read chars, in this 
case on the `db.txt` file.