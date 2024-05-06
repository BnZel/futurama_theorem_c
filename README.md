## Futurama Theorem C

My attempt at the futurama theorem. To see what applications can be done with it.

## Resources
* [Article](https://medium.com/@mikaeldavidsson/the-futurama-theorem-103980db677b)
* [Wiki](https://theinfosphere.org/Futurama_theorem)
* [Video](https://www.youtube.com/watch?v=ILmrtHlP9xY)

## Notes
![firstpage](./first_page.jpg)
![secondpage](./second_page.jpg)

## Output
When running the program, it will request the user to enter the number of people in order to start (entry must be greater than 2 people). 

```
How many people: 9
Entered: 9

-----INPUT-----
first cycle:
mind: 0 | body: 1
mind: 1 | body: 2
mind: 2 | body: 3
mind: 3 | body: 4
mind: 4 | body: 5
mind: 5 | body: 6
mind: 6 | body: 0

second cycle:
mind: 7 | body: 8
mind: 8 | body: 7

helpers:
mind: 10 | body: 10 
mind: 11 | body: 11

====================START====================

-----------------FIRST CYCLE-----------------

SWITCHING MIND:
mind: 11 | body: 11 <---> mind: 0 | body: 1


SWITCHED MIND:
mind: 0 | body: 11 <---> mind: 11 | body: 1


SWITCHING MIND:
mind: 10 | body: 10 <---> mind: 1 | body: 2


SWITCHED MIND:
mind: 1 | body: 10 <---> mind: 10 | body: 2


SWITCHING MIND:
mind: 0 | body: 11 <---> mind: 6 | body: 0


SWITCHED MIND:
mind: 6 | body: 11 <---> mind: 0 | body: 0


SWITCHING MIND:
mind: 6 | body: 11 <---> mind: 5 | body: 6


SWITCHED MIND:
mind: 5 | body: 11 <---> mind: 6 | body: 6


SWITCHING MIND:
mind: 5 | body: 11 <---> mind: 4 | body: 5


SWITCHED MIND:
mind: 4 | body: 11 <---> mind: 5 | body: 5


SWITCHING MIND:
mind: 4 | body: 11 <---> mind: 3 | body: 4


SWITCHED MIND:
mind: 3 | body: 11 <---> mind: 4 | body: 4


SWITCHING MIND:
mind: 3 | body: 11 <---> mind: 2 | body: 3


SWITCHED MIND:
mind: 2 | body: 11 <---> mind: 3 | body: 3


SWITCHING MIND:
mind: 2 | body: 11 <---> mind: 10 | body: 2


SWITCHED MIND:
mind: 10 | body: 11 <---> mind: 2 | body: 2


SWITCHING MIND:
mind: 1 | body: 10 <---> mind: 11 | body: 1


SWITCHED MIND:
mind: 11 | body: 10 <---> mind: 1 | body: 1


-----------------SECOND CYCLE-----------------

SWITCHING MIND:
mind: 10 | body: 11 <---> mind: 7 | body: 8


SWITCHED MIND:
mind: 7 | body: 11 <---> mind: 10 | body: 8


SWITCHING MIND:
mind: 11 | body: 10 <---> mind: 8 | body: 7


SWITCHED MIND:
mind: 8 | body: 10 <---> mind: 11 | body: 7


SWITCHING MIND:
mind: 7 | body: 11 <---> mind: 11 | body: 7


SWITCHED MIND:
mind: 11 | body: 11 <---> mind: 7 | body: 7


SWITCHING MIND:
mind: 8 | body: 10 <---> mind: 10 | body: 8


SWITCHED MIND:
mind: 10 | body: 10 <---> mind: 8 | body: 8


====================END====================

-----OUTPUT-----
mind: 1 | body: 1
mind: 2 | body: 2
mind: 3 | body: 3
mind: 4 | body: 4
mind: 5 | body: 5
mind: 6 | body: 6
mind: 0 | body: 0
mind: 8 | body: 8
mind: 7 | body: 7

x.mind: 10 | x.body: 10
y.mind: 11 | y.body: 11


```
