#Multiple-Window-Display
use 4 small windows to display the object in split-window mode.
1 large window to show the original view of object.
##How it works?
use hot key P to switch:
1. use the function glOrtho() to change the projection matrix
2. use the function glFrustum() to change the projection matrix

and in directory 'simple_way' , I use the viewport to map part of the origin window to a small window to implement the split-screen display,which is not very good, because the viewport will decrease the display area of the window,so the object is quite smaller than the original object.
