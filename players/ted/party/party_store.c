short() { return "Party Store"; }

long() {
   write("You are in the party store.\n");
   write("Each party in existance will have an object stored here\n");
   write("representing it.\n");
   write("As usual with these wizardly rooms, there are no exits.\n");
   return 1;
}

reset(arg) {
   if (!arg) set_light(1);
   return;
}





