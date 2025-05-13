inherit "obj/armor";
 
string fiance,fiancee,gem,size,num,size2,gem2,metal,size3,script;
 
reset(arg)
{
   if (!arg)
   {
      set_name("ring");
   }
}
short()
{
   write("An engagement ring from "+fiance+".\n");
}
 
 
long() {
        write("This is a beautiful engagement ring for "+fiancee+" from "+fiance+".\n");
write("It is a "+get_size()+" "+gem+", surrounded"+
" by "+num+" "+size2+" "+gem2+".\n");
        write("The ring itself is made of "+metal+" and is a size "+
        size3+".\n"+"  It bears the inscription:\n"+script+" ("+fiance+")\n");
}
 
init()
{
::init();
   add_action("set_size","size");
   add_action("set_fiance","fiance");
   add_action("fiance_me","fiancee");
}
 
 
set_size(arg)
{
   if (!arg)
   {
   write("What size?  You can choose from:\n small\n moderately sized\n"+
      " modest\n well sized\n large\nor\n HUMONGOUS\nWhat is your choice?\n");
      return 1;
      }
      else
   if (!(arg=="small"||"modestly sized"||"modest"||"well sized"||"large"||"HUMONGOUS"))
   {
      write("That's not a choice!  Type 'size' to get the sizes again.\n");
      return 1;
   }
   else
   {
 
write("You have chosen a "+arg+" gem.\n");
         size_it(arg);
      return 1;
   }
}
size_it(str) {
  size=str;
}
get_size(){ return size; }
 
set_fiance(arg)
{
   if(!arg)
   {
      write("You want your ring to be from Nobody?\n");
      propose(arg="Nobody!");
      return 1;
   }
   {
      write("This ring is now from "+arg+".\n");
      propose(arg);
      return 1;
   }
}
 
propose(arg)
{
   fiance=arg;
}
 
fiance_me(arg)
{
 
if(!arg)
   {
      write("You have to have someone's name for a variable!\n");
      return 1;
   }
   {
      write("This ring is now for "+arg+".\n");
   accept(arg);
   return 1;
   }
}
 
accept(arg)
{
   fiancee=arg;
}
