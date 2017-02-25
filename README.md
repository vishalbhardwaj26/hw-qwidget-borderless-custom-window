# helloworld-qwidget-borderless-custom-window

**To Run**
* Open it in Visual Studio 2015 and rebuild
  * To run it in visual studio
    * You need Visual studio 2015 (with update 2 or 3) + "C++" component installed with VS 
    * You need Qt integration with visual studio
       * [package need to be installed](https://visualstudiogallery.msdn.microsoft.com/c89ff880-8509-47a4-a262-e4fa07168408)
    * you might need [Qt 5.7](http://qt.mirrors.tds.net/qt/archive/online_installers/2.0/qt-unified-windows-x86-2.0.3-1-online.exe)
      * skip the user registeration part.
 
 **About App**
 * Frameless QWidget window with custom title bar and custom buttons.
 * Customize by overriding native “resize” , “mouse” and “paint” events.
 * Hover or focused border style on custom window/title bar.
 
 GUI: 
 
 <img src = "/QtInv/images/window.png" width="300" />
 
 **More Study**
 * Window frame is an OS specific thing  and is not drawn by Qt. Approach is disabling window frame entirely by setting Qt::FramelessWindowHint flag on your widget, and drawing the frame and buttons yourself. This gives you control of the look of the frame, but is also a lot of work, because you need to handle all the windowing behavior like resizing, moving, maximizing or Aero Shake yourself.
 * Frameless QMainWindow is resizable its own, but custom window or dialog need to have QSizeGrip to make it resizable.
 * Title bar cannot be configured with stylesheet. Title bar is provided by Window Manager.
