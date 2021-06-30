#! / bin / bash
ROOT_UID = 0
ÉXITO = 0
# Validación de usuario root
si [ " $ UID "  -ne  " $ ROOT_UID " ]
luego
  echo  " Se debe estar como root para ejecutar este script "
  salir  $ E_NOTROOT
fi  

archivo = $ 1
# VAlidaciòn de carga de archivo de lista.
si [ " $ {archivo} X "  =  " X " ] ;
luego
   echo  " Debe indicar el archivo del listado con Nombres de grupo a ingresar ... "
   salida 1
fi

crearGrupo () {
    # Iniciamos la recepciòn de la Devoluciòn del shell para el nombre del grupo
	eval nombreGrupo = " $ 1 "
	# Evaluamos la exitencia del grupo en la ruta etc / group
	si grep -q $ {nombreGrupo} / etc / group
    luego   # Si el grupo existe mandar alerta de existencia.
        echo  " Grupo [ $ {nombreGrupo} ] No se pudo agregar ... Ya existe "
	else  # Si no existe crear nuevo grupo y guardalo en una lista de gupos creados
        groupadd " $ {nombreGrupo} "
		echo  " Grupo [ $ {nombreGrupo} ] agregado correctamente ... "
        echo  " $ {nombreGrupo} "  >> ListaGruposCreados.csv
		
	fi
}

while IFS =: leer -r f1
hacer
	crearGrupo " \ $ {f1} "	
    # Funciòn de recepciòn de los datos.
hecho  <  $ {archivo}

salir 0