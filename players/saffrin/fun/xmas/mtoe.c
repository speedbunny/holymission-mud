inherit "obj/treasure";

reset(arg) {
    if(arg) return;
    set_id("A sprig of mistletoe");
    set_alias("mistletoe");
    set_weight(0);
    set_value(80000);
    set_short("A sprig of mistletoe");
    set_long("A sprig of mistletoe.  This is a sprig of mistletoe from Saffrin's\n"+
      "garden.  It makes someone special kiss you, including those not in the same rooms as you!\n"+
      "Use 'mistletoe <name>'.\n");
}

init()
{
    ::init();
    add_action("mistletoe", "mistletoe");
}

mistletoe(str) {
    object victim;
    victim=find_living(str);
    if(!victim) return write("There is no " + capitalize(str) + " on the game!\n");
    write("You use mistletoe to earn a kiss from " + capitalize(str) + "!!\n");
    write(capitalize(str) +" kisses you merrily.\n");
    say(this_player()->query_name() + " uses mistletoe to earn a kiss from " + capitalize(str) +
      "!\n",victim);
    say(capitalize(str) +" kisses "+ this_player()->query_name() +".\n",victim);
    tell_object(victim,this_player()->query_name() + " uses mistletoe to earn a kiss from you!\n");
       tell_object(victim,"You kiss "+this_player()->query_name() +".\n");
    if(random(2)) command("blush",victim);
    else command("smile",victim);
    return 1;
}
drop() {
    return 1;
}
