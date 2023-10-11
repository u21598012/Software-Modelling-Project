# Software-Modelling-Project
Use of design patterns to build a game similar to Dungeons and Dragons using object oriented programming in C++

The following scenario was used as a guide when implementing the project: 

A major concern during the development of any application is the concept of highly coupled code and why
we want to avoid this. Whenever code is ”highly-coupled” any change in one piece of code can and probably
will affect the manner in which other aspects of code perform. To alleviate this we concern ourselves with
seperation of concerns meaning we reduce the duplicity of our code and we ensure that we do not have to care
about what other code is doing to be able to perform our current function. For example we never care how
the network library we imported send the request and performs the underlying protocol, we only care that the
request comes back in a format that we can process.
Mediator allows us to clearly separate classes by controlling how communication is performed such that a
specific object does not need to have references to a number of other objects and needing to know their exact
interfaces. We rather have a mediator that any component of our application that needs to communicate can
send a message to and the mediator takes responsibility to inform the necessary objects. Almost like a post
office where we send letters then they go and deliver them to whom it concerns.
Similarly the iterator pattern allows us to traverse collections and data structures without us needing any
knowledge of how the data structure is organised. The data structure can be as simple or complex as desired
but we only care about if there is more data in the structure that still needs to be processed. We might
still want the ability to traverse the structure in different ways in which case we can define differing concrete
iterators that will again mean we do not need to care how, specifically, the traversal is implemented only that
we get the data needed to perform our current task.
Lastly we have the command pattern, this allows us to address code duplicity and a few other problems in a
very succinct manner. Whenever we write an application we might end up with the same action needing to
be performed by various objects that are not related. Meaning we would end up with duplicated code littered
across the code base. Or we can use the command pattern so that everywhere where we would execute the
action we rather create a command object and send that off to the relevant receiver to process. We also end
up with the ability to cue operations that might take some time and cannot be performed concurrently(Think
about a webserver needing to process incoming requests from multiple clients that may outnumber the number
of available threads) as well as the ability to keep a history of commands executed that can be used for various
functions such as auditing and the reversal of operations by performing the inverse of the operation, essentially
allowing us to ’Undo’ actions.

For this exercise we will be implementing a dungeon crawler/tower defense game in the likeness of the Dungeons
games. In this game we are in charge of building and protecting a lair from the heroes so that they cannot
find and destroy your treasure hoard. We will simplify the game down to the following components:
• The storyteller class
The storyteller is a concept from tabletop games where one ”player” takes the role of the storyteller/game
master. They decide when things happen that aren’t in the control of the player. In this case the
storyteller will be responsible for creating waves of heroes that will attempt to assault your lair that you
must then fight off.
• The lair class
Here we want to demonstrate the use of iterator by creating enemies that will search for the treasure.
The player will be responsible for building a lair, they will create ”tiles” that act as different rooms that
the heroes will move through in search of the treasure. A tile can connect to another tile in each of the
four cardinal directions allowing for the creation of a fully fledged lair. You will implement the iterator
pattern to perform depth first and breadth first traversals which the hero classes can then use to navigate
the lair as they should.
• the hero classes
These should be very simple classes where you can define different unit archetypes that may have different
health points or abilities. The crucial thing to demonstrate would be the use of different iterators based
on the decision made by the storyteller, whether a breadth or depth traversal would be preferred for the
current search. You can also decide rather than a single object being a hero, it could be a wave of heroes
traversing the lair together.
• Trap classes
These should again be very simple as we want to have the ability to place traps inside tiles to create
hazards for the heroes, dealing damage as they traverse the lair to try and eliminate the threat before
they stumble onto your treasure leading to the player losing the game.
• player interaction (Menu class)
This class should present the player with a menu so that they can interact with the game, the player
must be able to create or remove tiles from the lair, add traps to rooms, research new traps, manage the
research queue. They must also have a way to view their current wealth which will be used in the next
classes to manage resources used for research.
• The bank class
The bank class is responsible for keeping track of our current gold reserves. These gold reserves will be
used to fund research and will also be used as the health of the treasure hoard. when you run out of gold
the game end in defeat. If you manage to survive a certain number of waves you will be victorious.
• Research laboratory classes
The research class is where we will be using the command pattern. Research will allow us to create new
traps that we can build in rooms to slow down or eliminate the heroes. Here the is some freedom in
the manner in which the traps will function, straight damage to the heroes, or will it slow them down,
teleport them to a different tile. the research will however cost money to conduct and will take some time
to complete, this can be simulated by a turn counter that will count down until the research is concluded.
Because the research takes time to complete we want the ability to queue up multiple research tasks
to run after each other and to be able to remove tasks from the queue, hence the use of the command
pattern.
• The engine class.
This will be the heart of the game, whenever research is being queued by the player interface it will be
responsible for notifying the bank how much gold has been used to fund the research. When research
completes it will be notified by the research class and notify either the player interface about a new trap
that has been added to their arsenal or when a wave of heroes interacts with a trap will communicate
between the trap and the wave regarding damage or other effects inflicted on the wave.
