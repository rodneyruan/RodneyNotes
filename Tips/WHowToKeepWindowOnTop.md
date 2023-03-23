# How To Keep A Window Always On Top In Windows 10

#### Option #1: Use DeskPins

```bash
Click the DeskPin icon on your taskbar, and the mouse icon turns into a small, red pin.
Pin your window or program by clicking on the top part of the window. 
A small, red pin icon appears on the title bar of the pinned window to show its status.
```


### Option #2: Use AutoHotKey with Custom Scripting
```bash
Creat a new AutoHotKey script.
Type or paste the following onto the bottom of the file: 
    ^SPACE:: Winset, Alwaysontop, , A
Run the script.
Just press CTRL + SPACE on whatever window you want to stay on top.
```
