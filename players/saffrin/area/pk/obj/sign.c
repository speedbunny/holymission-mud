inherit "/obj/thing";
 
void reset(int flag) {

  ::reset(flag);
   if (flag == 0) {

      set_name("sign");
      set_short("A VERY, VERY important sign!");
      set_long("There is something written on it.\n");
      set_read(
     	"\t        WARNING!!!!!               \n"+
        "\tUp the staircase is the Elan Drac Asylum.  The patients\n"+
        "\thave taken over and the place is in chaos.  In here, murder\n"+
        "\tof anyone is permitted.\n\n"+
        "\tEnter at your own risk!!  Players can kill other players in\n"+
        "\there without legal recourse.  The inmates are the only law\n"+
        "\tup these stairs.\n\n"+
        "\tIn otherwords, this is an open and free playerkilling area.\n"+
        "\n"+
        "\tSaffrin\n");
   }
}

int get(){
     	return 0;
}
