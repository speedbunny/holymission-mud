inherit "room/room";


void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Prison cell";
    long_desc =
    "The cell contains a single cot attached to the wall by\n"+
    "two chains and a long hinge that allows it to be folded up\n"+
    "against the wall. A small hole has been cut through the stone\n"+
    "floor and is located at the inner left corner.\n";
    items = ({
      "cot", "The cot looks fairly comfortable",
      "walls", "The stone walls are thick and unpenetrable",
      "chains", "The chains are the main support for the cot",
      "hinge", "The hinge controls the chains that support the bed",
      "hole", "The small hole on the floor serves as the sanitary facility",
    });
}

