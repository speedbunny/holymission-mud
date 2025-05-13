inherit "/obj/treasure";
int i;

reset(arg){

if (arg) return;
 i=20;	 /* i=number of arrows in the quiver */
 set_alias("quiver_of_arrows");
 set_alt_name("quiver");
 set_name("quiver of arrows [small]");
 set_short("A quiver of arrows [small]");
 set_long("A quiver of arrows. It is full.\n");
 set_weight(1);
 set_value(200);
}

void dec_arrows(int how_many){
 i-=how_many;
 if (i<1){
    write("The quiver is empty. You destruct it.\n");
    destruct(this_object());
  }
}

 long(){

  if (i<50) return "The quiver is half full.\n";
  if (i<99) return "The quiver is nearly full.\n";
  }
