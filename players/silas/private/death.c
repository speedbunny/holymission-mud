int monster_died(object ob)
{
if(!this_player()->query_immortal())
{
shout(this_player()->query_name()+ " has destroyed the Evil Dark lord of Haden!\n");
return 0;
} else {
tell_room(environment(this_object()), "Evil dark lord is destroyed!\n",this_player());
write ("Sorry you are immortal it will not echoall.\n");
return 0;
}
return 1;
}
