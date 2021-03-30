#Instructions to run the file
1)Open the terminal and navigate to the folder containing the code
2)Store the location of image which needs to be processed in the code.

To compile the code use the command

```C
make all 
```

Then to execute the code use the command

```C
make run
```

After executing above commands, the terminal displays no.of frames in the video and fps at which video is executed.After running the video,the data is written to a data.text file which is converted to data.csv using a pythoncode that can be used for plotting graph in excel.For speeding up the process we are using every third frame for graph plotting and processing.For background subtraction we used an empty frame from the video which was saved as requiredimage.jpg in this directory.

For removing the executable use the command

```C
make clean
```