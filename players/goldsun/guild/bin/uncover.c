uncover(string str) {
	if(str!="tracks" && str!="marks") {
		notify_fail("Uncover what?\n");
		return 0;
	}
	return "players/portil/guild/tracks.c"->query_tracks();
}
