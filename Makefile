GAME_CPP = Game/CGame.cpp Game/CSettings.cpp Game/CResult.cpp
GAMEMODE_CPP = GameMode/CActionMode.cpp GameMode/CMainMenuMode.cpp GameMode/CTrainingMode.cpp
MAP_CPP = Map/CBrickTexture.cpp Map/CSpaceTexture.cpp Map/CTreeTexture.cpp
PLAYER_CPP = Player/CCoords.cpp Player/CEnemyPlayer.cpp Player/CPersonPlayer.cpp Player/CMeleeBullet.cpp Player/CRangedBullet.cpp
UI_CPP = UI/CButton.cpp UI/CCheckBox.cpp UI/CImageView.cpp UI/CUIBulletComponent.cpp UI/CUIEntireManager.cpp UI/CUIGameManager.cpp UI/CUIMainMenuManager.cpp UI/CUIPlayerComponent.cpp UI/CUIScreenHandler.cpp UI/CUIText.cpp UI/CUITile.cpp UI/CUITrainManager.cpp UI/CUIResultsManager.cpp
ALL_CPP = $(GAME_CPP) $(GAMEMODE_CPP) $(MAP_CPP) $(PLAYER_CPP) $(UI_CPP) main.cpp

GAME_H = src/Game/CGame.h src/Game/CSettings.h src/Game/CResult.h
GAMEMODE_H = src/GameMode/CActionMode.h src/GameMode/CMainMenuMode.h src/GameMode/CTrainingMode.h src/GameMode/CGameMode.h
MAP_H = src/Map/CBrickTexture.h src/Map/CSpaceTexture.h src/Map/CTreeTexture.h src/Map/CTexture.h
PLAYER_H = src/Player/CCoords.h src/Player/CEnemyPlayer.h src/Player/CPersonPlayer.h src/Player/CMeleeBullet.h src/Player/CRangedBullet.h src/Player/CBullet.h src/Player/CPlayer.h
UI_H = src/UI/CButton.h src/UI/CCheckBox.h src/UI/CImageView.h src/UI/CUIBulletComponent.h src/UI/CUIEntireManager.h src/UI/CUIGameManager.h src/UI/CUIMainMenuManager.h src/UI/CUIPlayerComponent.h src/UI/CUIScreenHandler.h src/UI/CUIText.h src/UI/CUITile.h src/UI/CUITrainManager.h src/UI/CUIResultsManager.h src/UI/CUIManager.h
ALL_H = $(GAME_H) $(GAMEMODE_H) $(MAP_H) $(PLAYER_H) $(UI_H)

OBJS := $(ALL_CPP:%=src/%.o)
LDLIBS = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
CXXFLAGS  = -Wall -pedantic -O3 -std=c++17
INCDIRS = -Isrc -I/usr/include/SDL2

.PHONY:all

all: compile doc

.PHONY:compile

compile: hlazkyau

hlazkyau: $(OBJS)
	g++ $(OBJS) -o $@ $(LDLIBS)

src/%.cpp.o: src/%.cpp
	@mkdir -p $(@D)
	g++ -c $< -o $@ $(CXXFLAGS) $(INCDIRS)

.PHONY:run

run: compile
	./hlazkyau

.PHONY:clean

clean:
	rm -f hlazkyau
	rm -rf doc
	rm -rf src/**/*.cpp.o
	rm -rf src/*.cpp.o

.PHONY:doc

doc: $(ALL_H) Doxyfile
	doxygen



