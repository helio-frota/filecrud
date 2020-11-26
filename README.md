# filecrud
CRUD operations in a file

This is using:

- `cmake-js`

  - It helps me to avoid to have this bash script:
    ```bash
    #!/bin/bash

    if [ ! -d "build" ]; then
      mkdir build
    fi

    cd build
    cmake -GNinja ..
    ninja
    ```

- `clang-format` (lint rules same as https://github.com/nodejs/node-addon-api/blob/master/.clang-format)

  - Installed the system package with `sudo apt install clang-format`

  - Installed the npm package as devDependency with `npm i clang-format -D`

  - Added that in package.json as npm script to avoid this bash script:
  ```bash
  #!/bin/bash
  # 1) find all files with extension .cc, .c and .h.
  # 2) excludes the generated build directory created by cmake.
  # 3) execute clang format.
  find . -regex '.*\.\(cc\|c\|h\)' -not -path "*/build/*" -exec clang-format -style=file -i {} \;
  ```
- `cmake` with basic configuration on CMakeLists.txt

- `NPM` package.json to automate build, run and lint with `npm it`

Interesting parts of the C code are:

- The `__fpurge` from `stdio_ext.h` to clean the
buffer and to have a consistent menu running in the loop.

- The `fputc` and `fgetc` from `stdio.h` to write and read chars, in this 
case on the `db.txt` file.

How to run:

```console
npm it
```