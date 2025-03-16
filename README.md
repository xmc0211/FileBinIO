# FileBinIO
File reading and writing basic tool for Windows.

You can specify the file, offset address, length, and a ```BYTE[]``` that stores the data.

You can use ```\\.\PhysicalDrive0\``` to directly read and write to the disk.

- - -

## example

If you have a txt file written with "Hello, xmc0211!", after executing

```cpp
BYTE[10] Buffer = { '\0' };
CH2UCH("FileBinIO!", Buffer, 10); // from Convert: https://github.com/xmc0211/Convert
FBWriteFile(TEXT("C:\\Path\\To\\Txt\\File.txt"), Buffer, NULL, 7, 10);
```

it will change to "Hello, FileBinIO!"
