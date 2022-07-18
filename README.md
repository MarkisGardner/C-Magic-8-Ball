# C-Magic-8-Ball
Magic 8 Ball

I created this game because it allowed me to learn and improve on \
a) using malloc and realloc.  While I was a professional programmer for 8 years, I never needed to use malloc and realloc.  My programming was very specific and 
we always allocated enough space at the beginning like with char array[50][50].  So, I was excited to learn and then use malloc and realloc in this program.\
b) using parameters.  In the unix environment we used -a, -b, -.....  With this dos environment we don't use the -'s.  So, I came up with a different way to handle
arguements with a parameter like -g good.txt where good.txt was filename for good replies.
c) using random.  We never used random in my workplace, so it was a nice tidbit to add.
d) because of using malloc and realloc I had to learn to pass "char ***array" instead of "char **array", so I could update the results.  To be honest, that took  
me a couple hours to get past the learning curve on that one.  But, it was a good learning experience.
e) learning to use fgets.  Again we never asked for input from the user so this was interesting.  When hitting enter and expecting the length to be 0, I was 
confused that it was 1 then I remembered that the enter key is \n.
f) The hardest part was knowing to use (*array)[num_of_lines] instead of *array[num_of_lines].  I couldn't understand why I kept getting an error.  Again, those of
you who have used malloc a lot would not have had any trouble with that.

There are two things I didn't do.
a) Completely break things up into very small pieces.  One function was a little long but it didn't repeat anything so I was happy with it.
b) Check to see if they sent arguements I was not expecting like k, z, a, etc....

I hope you enjoyed my game as a learning experience to learn how to program C.

To play
argument h tell you how to play
argument g good.txt will use only good manners to play the game
argument b bad.txt will use only bad manners to play the game.
if you use both g and b then it will randomly decide which one.
to end the game just hit enter.
