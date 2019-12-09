[Introducción]

Gracias a la expansion de la red y de la informacion en estos ultimos a~nos se puede acceder a una
gran cantidad de rescursos, compartir con gente en lugares distantes, en n, pero estos avances vienen
con diferentes problemas; el problema de transmitir informacion de forma correcta, eciente, rapida y
segura es uno de los mayores retos para el mundo entero. Es aqu donde la criptografa juega un papel
importante en la vida cotidiana de todo ser humano, permitiendole comunicarse a plenitud con el entorno
que le rodea sin temor alguno.
Hasta la fecha existen distintos modelos de criptografa, tales como RSA, cuantica, asimetrica, etc. Los
cuales cuentan con un desarrollo e investigacion muy avanzado. Sin embargo poco a poco han emergido
distintos modelos que buscan resolver el problema original desde otras perspectivas, indagando en areas
de la matematica que aun no han sido exploradas; como es el caso de la criptografa basada en fractales,
modelo en el cual nos preguntamos por la naturaleza de la geometra fractal y del caos en busca de
soluciones mas sencillas sin dejar de lado los aspectos importantes de un buen cifrado.
Tal como como es expuesto por Nadia y Mohamad [ASMM12] los sistemas de cifrado basados en
fractales1 son sistemas cuyo comportamiento no es facil determinar o predecir, siendo este un factor
decisivo a la hora de realizar criptoanalisis, ya que muchas de las tecnicas usadas en otros modelos
tradicionales de cifrado no se ajustan a la realidad de estos sistemas.
A su vez Ljupco [Lju01] en su trabajo explora los alcances y limitaciones que tienen los SCF, algunas
de las cuales llegan a tener un nivel de complejidad tan alto que no seran abordados en el presente trabajo.
Estas limitaciones son a su vez un factor motivante en el desarrollo del mismo; es por ello que hemos
denido INSIGNIAS con el n de resaltar los aspectos mas importantes de este documento.
Comenzaremos explorando por que resulta conveniente para nosotros el uso de fractales, Seccion 2.
La seccion 3 describe el algoritmo de cifrado a un nivel de detalle alto. La matriz de cifrado junto con la
funcion de cifrado, corazon de , son trabajadas en la seccion 4. El resultado y los detalles de transmision
para un mensaje seran expuestos en la seccion 5. La seccion 6 se encargara del algoritmo para descifrar
el mensaje y su funcionamiento. Por ultimo presentamos las conclusiones en la seccion 7.
