#!/bin/bash
ROOT_UID=0
SUCCESS=0

#Validaci�n de acceso root
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

file=$1

#Validaci�n de carga de la lista
if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo con el listado de usuarios a eliminar..."
   exit 1
fi

#Inicio de la funci�n
eliminarGrupo(){
	#Iniciamos la recepci�n de la Devoluci�n del shell para el nombre del grupo
	eval nombreGrupo="$1"
	#Validamos la exitencia del grupo en /etc/group si existe eliminar el grupo
	if grep -q ${nombreGrupo} /etc/group  
    then  
        groupdel "${nombreGrupo}"
		echo "Grupo[${nombreGrupo}] eliminado correctamente..."
	else #Si no exite mandar alerta de que no se puede eliminar por que no existe.
		echo "Grupo [${nombreGrupo}] No se pudo eliminar..."
	fi
}

while IFS=: read -r f1
do
	eliminarGrupo "\${f1}"	
    #Funci�n de recepci�n de los datos.
done < ${file}

exit 0