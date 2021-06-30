#!/bin/bash
ROOT_UID=0
SUCCESS=0
#VALIDACIÒN DE USUARIO ROOT.
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  
#VALIDACIÒN DE CARGAR LA LISTA.
file=$1
if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo del listado con Nombres de grupo a ingresar..."
   exit 1
fi

crearusuario() 
{
#Iniciamos la recepciòn de la Devoluciòn del shell
eval username="$1"
eval password="$2"
eval USERID="$3"
eval GROUPID="$4"
eval USERIDINFO="$5"
eval HOMEDIRECTORY="$6"
eval COMANDSHELL="$7"
echo "------------------------"
echo "Directorios en /home"
echo "------------------------"
echo "$HOME"#Llamada a directorios de Home
echo "------------------------"
    
    if grep -q ${GROUPID} /etc/group  #Si el ID del grupo exixste  crear usuario.
    then  
    echo "El grupo en el que quiere crear el usuario existe"
    echo "------------------------"
    echo "El shell es--> ${COMANDSHELL}"
    echo "El ID del grupo es-->${GROUPID}--> EXISTE"
    if grep -q ${username} /etc/passwd  #Si el usuario existe mandar aleta de existencia
    then 
    echo "------------------------"
    echo echo "El Usuario-->${username} --> EXISTE"
    echo "------------------------"
    else  #Si no exixte crear un nuevo usuario
    echo echo "El Usuario-->${username} --> NO EXISTE"
    echo "------------------------"
    echo "SE CREARA UN NUEVO USUARIO EN"
    echo "${HOMEDIRECTORY}" 
    echo "------------------------"
    #Argumentos para crear un nuevo usuario aginando ID,INFOMACIÒN,PASSWORD,NOMBRE DE USUARIO EJECUTAR CON EL SHEL DE LA RUTA DE BASH Y ASIGNAR UN ID DE GRUPO
    useradd -c "${USERID} ${USERIDINFO}"  -p "${password}" -d "${HOMEDIRECTORY}""${username}" -s "${COMANDSHELL}" "${username}"   -u  "${GROUPID}"       
    echo "*********************Usuario creado con exito*************"
    echo "------------------------"
    echo "Datos de nuevo usuario"
    echo "------------------------"
    echo "Usuario: ${username} - Contraseña: ${password} ....." 
    echo "El usuario ha sido guardado en la lista Lista_Usuarios_Creados.csv"
    echo ${username} >>Lista_Usuarios_Creados.csv #Guardamos los nombres de los usuarios en una lista
    fi
    else  #No existe el grupo por lo que crearemos un nuevo grupo
    echo "-----------------------------------------"
    echo "El grupo No existe"
    echo "-----------------------------------------"
    echo "Se creara un nuevo grupo con ID-->${GROUPID}"
    echo "-----------------------------------------"
    echo "El shell es--> ${COMANDSHELL}"
    echo "El ID del grupo es-->${GROUPID}-->NO EXISTE"
    echo "-----------------------------------------"
    groupadd "${GROUPID}"#Creaciòn de un nuevo grupo
    if grep -q ${username} /etc/passwd  #Nuevamente evaluamos la exitencia del usuario si existe no hacer nada
    then 
    echo "------------------------"
    echo echo "El Usuario-->${username} --> EXISTE"
    echo "------------------------"
    else  
    echo echo "El Usuario-->${username} --> NO EXISTE"
    echo "------------------------"
    echo "SE CREARA UN NUEVO USUARIO EN"
    echo "${HOMEDIRECTORY}" 
    echo "------------------------"
    fi
    #Argumentos para crear un nuevo usuario aginando ID,INFOMACIÒN,PASSWORD,NOMBRE DE USUARIO EJECUTAR CON EL SHEL DE LA RUTA DE BASH Y ASIGNAR UN ID DE GRUPO
    useradd  -c "${USERID} ${USERIDINFO}" -p "${password}" -d "${HOMEDIRECTORY}""${username}" -s "${COMANDSHELL}" "${username}"  -u "${GROUPID}"  
    echo "*********************Usuario creado con exito*************"
    echo "------------------------"
    echo "Datos de nuevo usuario"
    echo "------------------------"
    echo "Usuario: ${username} - Contraseña: ${password} ....." 
    echo "El usuario ha sido guardado en la lista Lista_Usuarios_Creados.csv"
    echo ${username} >>Lista_Usuarios_Creados.csv #Guardamos los nombres de los usuarios en una lista
    fi
}

while IFS=: read -r f1 f2 f3 f4 f5 f6 f7
do
 
    crearusuario "\${f1}" "\${f2}" "\${f3}" "\${f4}" "\${f5}" "\${f6}" "\${f7}"
    #Argumentos que va a resivir nuestra funciòn separados por : y con terminaciòn con \
done < ${file}

exit 0