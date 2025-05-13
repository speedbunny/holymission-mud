inherit "/secure/questdef";

void reset(status arg) {
 if (arg) return;
 set_author("Brainsprain");
 set_qname("dwarven_brothers");
  set_hint("There are two dwarven smiths in the Land of Bismarck.\n"+
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
           "\n"+
           "Prove to Thorin that his brother Thelgar is still alive.\n"+
           "This is a newbie quest but will take some real exploration\n"+
           "of the area surrounding Castle Bismarck.  Thorin is picky and\n"+
           "will only talk\n"+
           "to those that he thinks are dwarven.\n");
 set_req_place(br+"/armoury.c");
 set_req_caller(br+"/armoury.c");
set_qpoints(20);
}
}
