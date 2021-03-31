<b>Instructions to run the file</b><br>
1)Open the terminal and navigate to the folder containing the code.<br>
2)Store the location of image which needs to be processed in the code.<br>

To compile the code use the command<br>

```C
make all 
```

Then to execute the code use the command

```C
make run
```

After executing these commands, the terminal shows a prompt asking us to enter the parameter which is the no.of threads to be used to calculate the queue density.After executing above commands, the terminal displays no.of frames in the video and fps at which video is executed and the output is written to the file "using k threads.txt" where k is the parameter entered.

For removing the executable use the command

```C
make clean
```
