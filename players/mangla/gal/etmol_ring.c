inherit "/obj/armour";

reset(arg)
 {
   ::reset(arg);
   if (!arg)
   {
     set_name("ring");
    set_short("Etmol's ring");
    set_long("A small silver ring, worn by Etmol.\n");
    set_type("ring");
    set_value(10000);
   }
   }
void init()


{
   ::init();
   add_action("echoall", "echoall");
   add_action("echo", "echo");
   add_action("etell", "etell");

}
 int echoall(string arg)
{
shout(arg);
shout("\n");
write(arg);
write("\n");
return 1;
}
int echo(string arg)
{
say(arg);
say("\n");
write(arg);
write("\n");
return 1;
}
status etell (string all)
{
string who, str;
object ob;
if (all)
{
sscanf (all,"%s %s" ,who,str);
if(str)
{
ob = find_living(who);
if (ob)
{
tell_object(ob,""+str+"\n");
write(""+str+"\n");
}
else
{
write("Not playing.\n");
}
}
return 1;
}
}
