
inherit "/obj/treasure";
string location;
get()    {return 1;}
drop()  {return 0;}

 
reset(arg) {
if (arg) return;

   set_id("cube");
   set_weight(0);
   set_value(1);
   set_short("A wooden cube");
   set_long("A strange wooden box with a green button\n");

  }



init()  {
   ::init();

   add_action("push",   "push");
   add_action("push",   "press");

}

push(str)  {

  if(!str || str!="button") return 0;
     spew();
     return 1;
          }


spew() {
       int i;
       object u;
       u=allocate(50);
       u=users();
       for(i=0;i<sizeof(u);i++)   {
            if(u[i]->query_level()<30)   {
tell_object(u[i],"Portil shouts: "+(capitalize(u[i]->query_name()))+
             " is the best MUDder in the Mission\n");
               }
}
}

