inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Testroom";
    no_castle_flag = 1;
    long_desc =
              "This is a test-room, specially made for Hoppla and Helenette.\n"+
              "The walls are covered with some slimy stuff,\n"+
              "it could be anything: from blood to splattered frogs.\n"+
              "Here Hoppla can test certain monsters for Helenette.\n";
       items = ({
                 "walls","Walls covered with soft material",
                 "stuff","You try to see what it is, but it's hopeless",
                 "room","A test room",
                 "test room","A room used to kill new monsters",
                });
     dest_dir =({
                "players/helenette/room/top","down"
               });

    smell = "It smells really bad here.";
}
init(){
 ::init();
 this_player()->hit_player(1000,3);
return 1;
}
