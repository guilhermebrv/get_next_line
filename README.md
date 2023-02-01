# get_next_line - /42 Lisboa/

* The 'get_next_line' function is an utility function commonly used to `read a line` from a `file or input stream`, `one line at a time`. It is often used for reading large text files, where reading the entire file into memory would be impractical. The function reads the file or input stream `character by character` and `returns the full line`, `without the newline character`, each time it is called.

## Here's how the function works:

   * It `initializes a buffer` to `store the characters` read from the `file or input stream`. The buffer should be `large enough` to store a single line of text, but `not so large` as to cause `excessive memory usage`;
   * Then, the `read function` is called to read a `block of data` from the file or input stream `into the buffer`;
   * Iterates through the `characters` in the `buffer`, looking for the `newline character ('\n')`, which marks the `end of the current line`;
   * When a `newline character` is found, it `copies the characters from the buffer` up to, but `not including`, the `newline character` into a `separate string`, `returning` the `string` containing the `line of text`, as the result of the 'get_next_line' function;
   * If the `end of the file` or input stream has been `reached`, `return an empty string` or a `special marker` indicating that the end of the file has been reached;
   * `Repeat the above steps` until the `end of the file` or input stream is reached, or until an `error` occurs;
   * This function should be designed to `handle multiple file descriptors` (i.e., multiple open files or input streams) `at once`. This can be done by using a `separate buffer` for `each file descriptor` and `storing the current position` within `each buffer` in a `separate variable`.

It is important to note that the 'get_next_line' function should be implemented with `appropriate error handling` and `error reporting`, as well as `efficient memory usage`, to ensure that it works correctly and efficiently in all cases.
