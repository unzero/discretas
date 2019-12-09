# *Introducción

Gracias a la expansión de la red y de la información en estos últimos años se puede acceder a una
gran cantidad de rescursos, compartir con gente en lugares distantes, pero estos avances vienen
con diferentes problemas; el problema de transmitir información de forma correcta, eficiente, rápida y
segura es uno de los mayores retos para el mundo entero. Es aquí donde la criptografía juega un papel
importante en la vida cotidiana de todo ser humano, permitiendole comunicarse a plenitud con el entorno
que le rodea sin temor alguno.
Hasta la fecha existen distintos modelos de criptografía, tales como RSA, cuántica, asimétrica, etc. Los
cuales cuentan con un desarrollo e investigación muy avanzado. Sin embargo poco a poco han emergido
distintos modelos que buscan resolver el problema original desde otras perspectivas, indagando en áreas
de la matemática que aún no han sido exploradas; como es el caso de la criptografía basada en fractales,
modelo en el cual nos preguntamos por la naturaleza de la geometría fractal y del caos en busca de
soluciones más sencillas sin dejar de lado los aspectos importantes de un buen cifrado.
Tal como como es expuesto por Nadia y Mohamad [ASMM12] los sistemas de cifrado basados en
fractales1 son sistemas cuyo comportamiento no es fácil determinar o predecir, siendo este un factor
decisivo a la hora de realizar criptoanálisis, ya que muchas de las técnicas usadas en otros modelos
tradicionales de cifrado no se ajustan a la realidad de estos sistemas.
A su vez Ljupco [Lju01] en su trabajo explora los alcances y limitaciones que tienen los SCF, algunas
de las cuales llegan a tener un nivel de complejidad tan alto que no serán abordados en el presente trabajo.
Estas limitaciones son a su vez un factor motivante en el desarrollo del mismo; es por ello que hemos
definido INSIGNIAS con el n de resaltar los aspectos más importantes de este documento.
Comenzaremos explorando por qué resulta conveniente para nosotros el uso de fractales, Sección 2.
La sección 3 describe el algoritmo de cifrado a un nivel de detalle alto. La matriz de cifrado junto con la
función de cifrado, corazón de , son trabajadas en la sección 4. El resultado y los detalles de transmision
para un mensaje serán expuestos en la sección 5. La sección 6 se encargara del algoritmo para descifrar
el mensaje y su funcionamiento. Por último presentamos las conclusiones en la sección 7.

# Para más detalles consultar el archivo "Book.pdf"
