string name;
int is_locked;


set_lock(arg) {
    is_locked = arg;
}


query_lock() {
    return is_locked;
}

set_who_in_area(arg) {
    name = arg;
}

query_who_in_area() {
   if(!name)
    return "";
     else
    return name;
}

