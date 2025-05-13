#define TP      this_player()

inherit "room/bars";

int _read(string str) {

    if(str == "sign") {
        menu();
        return 1;
    }
    return 0;
}

reset(arg) {

    object drunkard;

    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc="The laughing unicorn";
    long_desc="You're in the Laughing Unicorn Pub.\n" +
              "There is a sign on the wall, that shows the prices.\n";
    dest_dir=({
		"players/bobo/krooms/mythwood/faun_mark1","south",
             });

    items = ({
              "sign","It's written in the common language, you can read it",
            });

    menu_title="Our prices :\n"+
               "--------------------\n";
    menu_desc=({
                ({ "cervisia","A Faunen cervisia",2,5,1,
                              "Well, not bad.\n" }),
                ({ "milk","A unicorn's milk",75,300,2,
                              "Didn't expect that.\n" }),
                ({ "brew","The druid's original mistletoe-brew",80,200,1,
                              "Your throat seems to burn, but you feel well.\n" }),
                ({ "berry","A berry",10,70,0,
                              "A strange flavor, but refreshing?\n" }),
              });

    if(!drunkard) {
	drunkard=clone_object("players/bobo/kmonster/drunkard");
        move_object(drunkard,this_object());
    }
}

init() {
    ::init();
    add_action("read","read");
}

read(str) {

    if(str=="sign") {
        menu();
        return 1;
    }
}

