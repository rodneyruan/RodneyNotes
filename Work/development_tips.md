### Object Dump
#### XB7 Object dump
```
cd build-arrisxb7arm-sdk72x
./tmp/sysroots-components/x86_64/binutils-cross-armeb/usr/bin/armeb-rdk-linux-gnueabi/armeb-rdk-linux-gnueabi-objdump  -S -D -l -x -s  ./tmp/work/arm1176jzsb-rdk-linux-gnueabi/ncsdk/1.0+intelsdk0-r0/package/usr/sbin/.debug/ggncs >ggncs.txt
```
在 C:\Work\Code\PUMA7 保存了一份ggncs.txt， 可以显示每一行代码
