
inherit "/obj/std_shadow";

int catch_tell(string str) {

    string blah,blah1;

    if(sscanf(str,"%s shouts: %s",blah,blah1)==2 ||
       sscanf(str,"%s bellows %s",blah,blah1)==2 ||
       sscanf(str,"%s quaff %s",blah,blah1)==2 ||
       sscanf(str,"%s bellowing %s",blah,blah1)==2 ||
       sscanf(str,"%s bawls: %s",blah,blah1)==2) {
        return 0;
    }
    write(str);
    return 1;
}


int priv_shad()
{
    return 1;
}

object priv_object()
{
     return this_object();
}

