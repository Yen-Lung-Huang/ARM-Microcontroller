<<<<<<< HEAD

SECTIONS
{
    _sdram_lma = .;
    sdram_region :
    AT ( _sdram_lma )
    {
        *(sdram_region)
    } >sdram
}
=======

SECTIONS
{
    _sdram_lma = .;
    sdram_region :
    AT ( _sdram_lma )
    {
        *(sdram_region)
    } >sdram
}
>>>>>>> 16c66438 (Upload from PC.)
