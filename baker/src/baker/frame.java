/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package baker;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Random;
import javax.swing.JOptionPane;

/*MANEJO DE LA GRAFICA*/
import de.erichseifert.gral.data.DataTable;
import de.erichseifert.gral.plots.XYPlot;
import de.erichseifert.gral.ui.InteractivePanel;
import java.awt.BorderLayout;
import java.awt.Color;
import javax.swing.JPanel;

/**
 *
 * @author unzero
 */
public class frame extends javax.swing.JFrame {

    /**
     * Creates new form frame
     */
    public frame() {
        initComponents();
        read_init_config();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jTextField1 = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        jTextField2 = new javax.swing.JTextField();
        jTextField3 = new javax.swing.JTextField();
        jButton1 = new javax.swing.JButton();
        jTabbedPane1 = new javax.swing.JTabbedPane();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("Iteraciones");

        jLabel2.setText("Punto");

        jButton1.setText("Graficar");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jTabbedPane1)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel1)
                            .addComponent(jLabel2))
                        .addGap(40, 40, 40)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jTextField1, javax.swing.GroupLayout.PREFERRED_SIZE, 89, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jTextField2, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jTextField3, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(41, 41, 41)
                        .addComponent(jButton1)
                        .addGap(0, 312, Short.MAX_VALUE)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel1)
                            .addComponent(jTextField1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel2)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                .addComponent(jTextField2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(jTextField3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(22, 22, 22)
                        .addComponent(jButton1)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jTabbedPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 397, Short.MAX_VALUE)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        // TODO add your handling code here:
        jTabbedPane1.removeAll();
        if(jTextField1.getText().equals("") || jTextField2.getText().equals("") || jTextField3.getText().equals("")){
            JOptionPane.showMessageDialog(this, "Por favor ingrese todos los datos", "Error",JOptionPane.ERROR_MESSAGE);
        }else{
            try{
                int u = Integer.parseInt(jTextField1.getText());
                int x = Integer.parseInt(jTextField2.getText());
                int y = Integer.parseInt(jTextField3.getText());
                DataTable data = new DataTable(Double.class,Double.class);
                generate_encode_matrix(u,data,new Pair(x,y));
                plot(data,"Q vs CF");
            }catch(NumberFormatException ex){
                System.err.println("Error!");
            }
        
        }
    }//GEN-LAST:event_jButton1ActionPerformed

    /**
     * AYUDA A GRAFICAR DENTRO DE UN PLANO CARTESIANO UNA COLECCION DE DATOS, Y UBICARLOS DENTRO DEL PANEL DESTINADO PARA SER MOSTRADOS.a
     * @param data LOS DATOS QUE SE GRAFICARAN
     * @param head EL TITULO DE LA PESTAÑA
     */
    private void plot(DataTable data,String head){
        XYPlot plot = new XYPlot(data);
        JPanel panel = new JPanel(new BorderLayout());
        panel.add(new InteractivePanel(plot),BorderLayout.CENTER);
        this.jTabbedPane1.addTab(head,panel);
        plot.getPointRenderer(data).setColor(Color.BLUE);
        panel.updateUI();
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(frame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(frame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(frame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(frame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new frame().setVisible(true);
            }
        });
    }
    
    /*METODOS ORIGINALES DEL SCF*/
    void generate_encode_matrix(int u,DataTable data,Pair<Integer,Integer> point){
	for(int x=0;x<u;++x){
		point = generate_baker_psi(data,point);
	}
    }

    /**
    *GENERA LAS LLAVES (CONJUNTO LAMBDA Y SIGMA) PARA LA TRANSFORMACION DE BAKER
    *SE EVITAN GENERAR CONJUNTOS DE SOLO 1'S {1,1,1,...,1} O EL CONJUNTO {N}
    */
    void generate_baker_keys(){
            do{
                    sigma.clear();
                    lambda.clear();	
                    int ac = n;
                    while(ac>0){
                            int nx = rand.nextInt(ac) + 1;
                            if(nx>0 && n%nx == 0){
                                    lambda.add(nx);
                                    ac -= nx;
                            }
                    }	
                    sigma.add(0);
                    for(int x=0;x<lambda.size()-1;++x){
                            sigma.add(sigma.get(x)+lambda.get(x));
                    }
            }while(lambda.size() == 0 || lambda.get(0)==n || lambda.size()==n);
    }

    /**
    *EVALUA LA TRANSFORMACION DISCRETA DE BAKER SOBRE B_{N,LAMBDA}(X,Y)
    */
    Pair<Integer,Integer> baker_map(int x,int y){
            int xp,yp,index=0;
            while(!(sigma.get(index)<=y && y<sigma.get(index)+lambda.get(index) ))index++;
            int qi = n/lambda.get(index);
            xp = n - sigma.get(index) - 1 - (int)Math.floor((n-x-1)/qi);
            yp = (qi)*(y-sigma.get(index)) + ((n-x-1)%qi);
            return new Pair(xp,yp);
    }

    /*
    *APLICA LA TRANSFORMACION DE BAKER A LA MATRIZ
    * -PRIMERO GENERA UN CONJUNTO DE LLAVES
    * -APLICA B_{N,LAMBDA}(PSI)
    * -ELIMINA LAS LLAVES USADAS
    */
    Pair<Integer,Integer> generate_baker_psi(DataTable data,Pair<Integer,Integer> point){
            /*GENERADO DE LAS LLAVES PARA LA MATRIZ*/
            generate_baker_keys();
            
            /*SE GENERA UNA NUEVA MATRIZ, EN BLANCO*/
            LinkedList<LinkedList<Character> > new_encode_matrix = new LinkedList<LinkedList<Character> >();
            for(int i=0;i<n;++i){
                    LinkedList<Character> new_vector = new LinkedList<Character>();
                    new_encode_matrix.add(new_vector);
                    for(int j=0;j<n;++j){
                            new_encode_matrix.get(i).add(' ');
                    }
            }

            /*SE EVALUA LA TRANSFORMACION DE BAKER Y UBICA EN LA NUEVA MATRIZ*/
            for(int i=0;i<n;++i){
                    for(int j=0;j<n;++j){
                            Pair<Integer,Integer> new_pos = baker_map(i,j);
                            new_encode_matrix.get(new_pos.first).set(new_pos.second,encode_matrix.get(i).get(j));
                            encode_index.put(encode_matrix.get(i).get(j), new_pos);
                            if(point.equals(new Pair(i,j))){
                                data.add(point.first*1.0,point.second*1.0);
                                point = new_pos;
                            }
                    }
            }

            /*REMPLAZA LA ANTIGUA MATRIZ*/
            encode_matrix = new_encode_matrix;   
            //print_keys();
            /*BORRADO DE LLAVES*/
            lambda.clear();
            return point;
    }

    /*METODO PARA IMPRESION DE LLAVES*/
    void print_keys(){
        StringBuilder line = new StringBuilder("[");
        for(int x=0;x<lambda.size();++x){
            line.append(lambda.get(x)+", ");
        }
        line.setLength(line.length()-2);
        line.append("]");
        JOptionPane.showMessageDialog(this, "Conjunto de llaves: \n"+line.toString(),"Mensaje",1);
        
    }
    
    /*METODO DE LECTURA PARA LA CONFIGURACION INICIAL*/
    void read_init_config(){
        BufferedReader reader = null;
        /*try{
           String new_line;
           reader = new BufferedReader(new FileReader("./confg.txt"));
           new_line = reader.readLine();
           n = Integer.parseInt(new_line);
           new_line = reader.readLine();
           q = Integer.parseInt(new_line);
           for(int x=0;x<n;++x){
               new_line = reader.readLine();
               LinkedList<Character> tmp = new LinkedList<Character>();
               encode_matrix.add(tmp);
               for(int y=0;y<n;++y){
                   encode_matrix.get(x).add(new_line.charAt(y));
                   encode_index.put(new_line.charAt(y),new Pair(x,y));
               }
           }
        }catch(IOException ex){
            ex.printStackTrace();
            JOptionPane.showMessageDialog(this, "FALTA EL ARCHIVO DE CONFIGURACION INICIAL, EL PROGRAMA SE CERRARA", "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(-1);
        }*/
        /*LLENADO MANUAL*/
        n = 100;
        q = 1800;
        for(int x=0;x<n;++x){
               LinkedList<Character> tmp = new LinkedList<Character>();
               encode_matrix.add(tmp);
               for(int y=0;y<n;++y){
                   encode_matrix.get(x).add('A');
               }
           }
    }
    
    /*CAMPOS PARA EL PROGRAMA*/
    int n,q;
    Random rand = new Random();
    LinkedList<LinkedList<Character> > encode_matrix = new LinkedList<LinkedList<Character> >();
    HashMap<Character,Pair<Integer,Integer> > encode_index = new HashMap<Character,Pair<Integer,Integer> >();
    LinkedList<Integer> lambda = new LinkedList<Integer>();
    LinkedList<Integer> sigma = new LinkedList<Integer>();
    
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JTabbedPane jTabbedPane1;
    private javax.swing.JTextField jTextField1;
    private javax.swing.JTextField jTextField2;
    private javax.swing.JTextField jTextField3;
    // End of variables declaration//GEN-END:variables
}

class Pair<F, S> {
    public F first; //first member of pair
    public S second; //second member of pair

    public Pair(F first, S second) {
        this.first = first;
        this.second = second;
    }

    public void setFirst(F first) {
        this.first = first;
    }

    public void setSecond(S second) {
        this.second = second;
    }

    public F getFirst() {
        return first;
    }

    public S getSecond() {
        return second;
    }
    
    public boolean equals(Pair<F,S> other){
        if(other.first == this.first  && other.second == this.second)return true;
        return false;
    }
}