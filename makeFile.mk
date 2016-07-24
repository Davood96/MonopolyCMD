#makeFile

#OBJECTS macro is the list of objects
#used in this program
OBJECTS = Main.obj Board.obj RandomCardDeck.obj Player.obj PlayerManager.obj Property.obj OtherSpaces.obj


Main.exe: $(OBJECTS)
	link.exe /out:$@ $**

Main.obj: Main.cpp Board.h Player.h PlayerManager.h
	cl -c Main.cpp 

Board.obj: Board.cpp Board.h RandomCardImp.h PropertyChildren.h CardTypes.h
	cl -c Board.cpp

RandomCardDeck.obj: RandomCardDeck.cpp RandomCardDeck.h RandomCard.h Player.h CardTypes.h
	cl -c RandomCardDeck.cpp

Player.obj: Player.cpp Player.h Die.h Group.h Property.h
	cl -c Player.cpp

PlayerManager.obj: PlayerManager.cpp PlayerManager.h Player.h Die.h Board.h
	cl -c PlayerManager.cpp

Property.obj: Property.cpp Property.h Player.h
	cl -c Property.cpp

OtherSpaces.obj: OtherSpaces.cpp Jail.h Player.h
	cl -c OtherSapces.cpp  
