y() {
mixed *a;

    a=({ ({ "a", "b" }), ({ "b", 1 }), ({ "c", 3, 4 }) });

    a = slice_array(a,0,0)+slice_array(a,2,2);

    return a;
} 
