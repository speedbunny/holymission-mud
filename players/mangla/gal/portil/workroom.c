inherit "/room/room";

reset(arg) {
    if(arg) return;

set_light(1);
    short_desc="Portil`s Workroom";
    long_desc="You are standing in the cosy workroom of Portil.\nThis is where he pours through reams of paper in order to remove the bug\nthat stops you destructing yourself when you really wanted to `say Hello`.\nIt seems there is some half written code on a table here but it\nmakes no sense to you at all.\n";
    

    dest_dir=({
	"room/church","chu",
	"room/post","post",
	"players/portil/games/othello","othello",
	"players/herp/games/4win","con4",
	"players/portil/rooms/uni/grounds1","uni",
	"players/portil/rooms/uni/hut","hut",
	"players/portil/rooms/sky/sky1","sky",
	"players/matt/newworld/city/rooms/votebooth","vote",
	"players/tuppence/workroom","tuppence",
	"players/bonzo/workroom","bonzo",
	"players/haplo/workroom","haplo",
	"players/herp/workroom","herp",
	"players/darastor/workroom","darastor",
	"players/nokey/workroom","nokey",
	"players/silas/workroom","silas",
	"players/galadriel/workroom","galadriel",
        "/room/post","post",
	"/players/tegerl/workroom","tegerl",
	"/players/colossus/workroom","colossus",
	"/players/tristan/workroom","tristan",
	"players/airborne/workroom","airborne",
	"players/helenette/workroom","helenette",
	"players/jewel/workroom","jewel",
	"players/cashimor/workroom","cashimor",
	"players/kawai/workroom","kawai",
	"players/starslayer/workroom","starslayer",
	"players/animal/workroom","animal",
	"players/katana/workroom","katana",
        "players/texas/workroom","texas",
    });                  
}
