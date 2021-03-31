<b>Instructions to run the file</b><br>
1)Open the terminal and navigate to the folder containing the code<br>
2)Store the location of image which needs to be processed in the code.<br>

To compile the code use the command

```C
make all 
```

Then to execute the code use the command

```C
make run
```

After executing above commands, a window is opened  containing the image.Using the left button of mouse click the top-left,bottom-left,bottom-right,top-right corners in order to select the four points for perspective mapping.Then you can use a left click or right click on the window or press on keyboard to close the window. A new window is opened which is the projection of previous image.Using the left button of mouse click the top-left and bottom-right corners of the projected image.Then you can use a left click or right click on the window or press on keyboard to close the window.A new cropped image will be produced which can be closed by right clicking on it.The cropped image and projected image are saved in the directory.

For removing the executable use the command

```C
make clean
```
