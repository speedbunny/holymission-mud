#define COST	20
#define DEST	"/players/saffrin/area/tower/room/outer"

int main() {
    string msg1,msg2;
    object mage,old,new;

    mage=this_player();
    if(!mage)
        return 0;
    else
        old=environment(mage);
    catch(DEST->a_load_fun());
    new=find_object(DEST);
    if(!new) {
        write("You don't think that would work somehow.\n");
        return 1;
    }
    else if(old==new) {
        write("You sense that you have not moved anywhere.\n");
        return 1;
    }
    else if(old && old->query_property("no_teleport")) {
        write("There is something in the area blocking your spells.\n");
        return 1;
    }
    else if(this_player()->query_sp()<COST && !mage->query_immortal()) {
        write("You do not have enough energy.\n");
        return 1;
    }
    else {
        if(!mage->query_immortal())
            mage->restore_spell_points(-COST);
        if(old)
            mage->setenv("GOBACK_ENV",old);
        else
            write("Warning! No room to goback to!\n\n");
        write("You create a swirling green portal and quickly jump \
into it before it closes.\n");
        msg1=sprintf("%s creates a swriling green portal.\n",
                     mage->query_name());
        msg2="Someone creates a swriling green portal.\n";
        say(msg1,mage,mage,msg2);
        tell_room(new,"A swirling green portal appears from thin \
air.\n");
        mage->move_player("into the portal",new);
        msg1="The portal vanishes.\n";
        if(old)
            tell_room(old,msg1);
        tell_room(new,msg1);
        return 1;
    }
}
