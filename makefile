build:
	g++ -o obj2usd obj2usd.cpp -lassimp
	g++ -o obj2ply obj2ply.cpp -lassimp
	g++ -o obj2fbx obj2fbx.cpp -lassimp