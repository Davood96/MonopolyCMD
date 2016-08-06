#makeFile

#OBJECTS macro is the list of objects
#used in this program
OBJ_DIR = ../Objects/
EXE_DIR = ../
HEAD_DIR = ../Headers/
OBJECTS = $(OBJ_DIR)*
MOVE = move


$(EXE_DIR)Main.exe: $(OBJECTS)
	link.exe /out:$@ $(OBJ_DIR)*

$(OBJ_DIR)Main.obj: Main.cpp $(HEAD_DIR)Board.h $(HEAD_DIR)Player.h $(HEAD_DIR)PlayerManager.h
	cl -c Main.cpp /Fo$(OBJ_DIR)

$(OBJ_DIR)Board.obj: Board.cpp $(HEAD_DIR)Board.h $(HEAD_DIR)RandomCardImp.h $(HEAD_DIR)PropertyChildren.h $(HEAD_DIR)CardTypes.h
	cl -c Board.cpp /Fo$(OBJ_DIR)

$(OBJ_DIR)RandomCardDeck.obj: RandomCardDeck.cpp $(HEAD_DIR)RandomCardDeck.h $(HEAD_DIR)RandomCard.h $(HEAD_DIR)Player.h $(HEAD_DIR)CardTypes.h $(HEAD_DIR)DList.h
	cl -c  RandomCardDeck.cpp /Fo$(OBJ_DIR)

$(OBJ_DIR)Player.obj: Player.cpp $(HEAD_DIR)Player.h $(HEAD_DIR)Die.h $(HEAD_DIR)Group.h $(HEAD_DIR)Property.h
	cl -c Player.cpp /Fo$(OBJ_DIR)

$(OBJ_DIR)PlayerManager.obj: PlayerManager.cpp $(HEAD_DIR)PlayerManager.h $(HEAD_DIR)Player.h $(HEAD_DIR)Die.h $(HEAD_DIR)Board.h
	cl -c PlayerManager.cpp /Fo$(OBJ_DIR)

$(OBJ_DIR)Property.obj: Property.cpp $(HEAD_DIR)Property.h $(HEAD_DIR)Player.h
	cl -c Property.cpp /Fo$(OBJ_DIR)

$(OBJ_DIR)OtherSpaces.obj: OtherSpaces.cpp $(HEAD_DIR)Jail.h $(HEAD_DIR)Player.h $(HEAD_DIR)TaxSpace.h
	cl -c OtherSpaces.cpp /Fo$(OBJ_DIR)  
