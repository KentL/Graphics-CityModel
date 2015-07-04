Project:City Model
Author:Zhuokun Li
Date: Dec,5,2014

The extra part I did is lighting, road generation and a part of collision detection. In terms of lighting ,I set diffuse and ambient and direction light and the direciton light will move as a circle. In terms of road, I created  zebra crossings at which one road crosses with the other. The position of the road will change with the city when the city is generated randomly. I also did a collision detection to the ground but didn't make one to the building. The collision detection code for the buildings could be found in the collidetest.cpp but it doesn't work well.

I also want to create some lamp-posts and signposts along the road and different building shapes too. My idea is that,since 
I first divide the whole ground into 900(30*30) grids(let me call it grid space),I can generate objects's coordinates(buildings and roads) in world space from it and I can also read a model's data that is occupying a certain  grids. So that I can know how high , wide and long it is in order to calculate the shape and size of which the object I want to add to it.
The same idea can also be used in putting lamp-posts and cars on the road. I also want to generate a normal map for the texture but it seems a little bit troublesome. To do the collision test, I found several math algorithms and one of them can work on detecting the collision with the ground which has no border.But when it comes to detect the buildings, there are many bugs that I can't fix it now.

You can control you movement with'w','A','S','D' on you key board and control you view direction using your mouse or using 
the direction keys 'UP' 'DWON' 'LEFT' and 'RIGHT'. Press 'R' to generate a new city model randomly. And press 'esc' to exit the game. Hope you enjoy it.


