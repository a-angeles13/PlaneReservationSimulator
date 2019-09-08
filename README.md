# PlaneReservationSimulator
Plane Reservation Simulator allows for a user to log in and view available seats through a display in the output terminal. The user can perform a number of actions including making reservations, canceling reservations, asking for assistance with the use of the program, request statistics about the flight, and save the current seating chart to a text file. This project is coded in C++ and is interfaced through the output terminal. 

Before running the Program must have access to the following files: 
chartIn.txt
updateChart.txt
systemUser.txt
statistics.txt 

chartIn should have the following text (Note "X" denotes a taken seat):
1	A	B	C	D	E	F
2	A	B	C	D	E	F
3	A	B	C	D	E	F
4	A	B	C	D	E	F
5	A	B	C	D	E	F
6	A	B	C	D	E	F
7	A	B	C	D	E	F
8	A	B	C	D	E	F
9	A	B	C	D	E	F
10	A	B	C	D	E	F

updateChart.txt is a file you wish to print the current seating chart next to (it is defined by user input and therefore can have a different name if desired"). 

systemUser.txt should follow the following format: 
01	Dexter	Cavanaugh	retxed	admin
02	Dee	Dee	notdexter	00000
03	Mandark	Astronomy	mandark	dark42
04	admin	admin	admin	admin

user# Firstname Lastname Username Password 

statistics.txt is a blank txt file which is printed to when the Statistics command is selected. 
