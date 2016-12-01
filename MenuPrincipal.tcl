#!/usr/local/bin/wish8.2 -f
#

set MSG "0"
set  "0"
set numero ""
set FLAG "0"

# Titulo
frame .f1 -relief groove -borderwidth 5 -background blue
label .f1.agenda -text " Estimacion de Costos " \
	      -font -*-times-medium-i-normal--24-*-*-*-p-125-*
pack .f1.agenda -side top
pack .f1

# Widget Output
frame .f3 -relief groove -borderwidth 1
entry .f3.msg -width 30 -relief sunken -textvariable MSG
pack .f3.msg -side top
pack .f3


set programa [open "| ./CalculadoraDeCostos" r+ ]


# Procedimiento de Busqueda
proc uno {} {
    global numero
    set numero "1"
    agrega
}
proc dos {} {
    global numero
    set numero "2"
    agrega
}
proc tre {} {
    global numero
    set numero "3"
    agrega
}
proc cua {} {
    global numero
    set numero "4"
    agrega
}
proc cin {} {
    global numero
    set numero "5"
    agrega
}
proc sei {} {
    global numero
    set numero "6"
    agrega
}
proc sie {} {
    global numero
    set numero "7"
    agrega
}
proc och {} {
    global numero
    set numero "8"
    agrega
}
proc nue {} {
    global numero
    set numero "9"
    agrega
}
proc cer {} {
    global numero
    set numero "0"
    agrega
}
proc enter {} {
    global programa
    global MSG
    global FLAG
    set FLAG "1"
    puts $programa [format "N:%s\n"  $MSG]
    flush $programa
    recibe_men
}
proc clr {} {
    global numero
    global FLAG
    set FLAG "1"
    set numero "C"
    mandar
}
proc sin {} {
    global numero
    global ARCH
    global FLAG
    set FLAG "1"
    set numero [format "GFILE:%s" $ARCH]
    mandar

}
proc par {} {
    global numero
    global ARCH
    global FLAG
    set FLAG "1"
    set numero [format "UFILE:%s" $ARCH]
    mandar
}
proc del {} {
    global numero
    global FLAG
    set FLAG "1"
    set numero "D"
    mandar
}
proc base {} {
    global numero
    global FLAG
    set FLAG "1"
    set numero "B"
    mandar
}
proc fact {} {
    global numero
    global FLAG
    set FLAG "1"
    set numero "F"
    mandar
}
proc sl {} {
    global numero
    global FLAG
    set FLAG "1"
    set numero "L"
    mandar
}
proc sr {} {
    global numero
    global FLAG
    set FLAG "1"
    set numero "R"
    mandar
}
proc pot {} {
    global numero
    global FLAG
    set FLAG "1"
    set numero "P"
    mandar
}
proc swp {} {
    global numero
    global FLAG
    set FLAG "1"
    set numero "I"
    mandar
}
proc mas {} {
    global numero
    global FLAG
    set FLAG "1"
    set numero "+"
    mandar
}
proc menos {} {
    global numero
    global FLAG
    set FLAG "1"
    set numero "-"
    mandar
}
proc por {} {
    global numero
    global FLAG
    set FLAG "1"
    set numero "*"
    mandar
}

proc agrega {} {
    global numero
    global MSG
    global FLAG
    if {$MSG!="0" && $FLAG=="0"} then {
	set MSG [format "%s%s" $MSG  $numero]
    } else {
	set FLAG "0"
	set MSG $numero
    }
}

proc mandar {} {
    global numero
    global programa
    puts $programa [format "%s\n"  $numero]
    flush $programa
    recibe_men
}

proc recibe_men {} {
	global MSG
	global programa
	gets $programa line
	set fields [split $line :]
	set i [lsearch $fields "MSG"]
	set MSG [lindex $fields [expr $i + 1]]
}

proc sal {} {
	global MSG
	global programa
	global bno
	set bno "O\n"
	puts $programa [format "%s" $bno]
	flush $programa
	{exit}
}
