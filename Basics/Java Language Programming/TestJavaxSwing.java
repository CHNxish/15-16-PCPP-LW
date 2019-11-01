/* Test javax.swing.* */
import javax.swing.*;

public class TestJavaxSwing{
    public static void main(String[] args){
        /* 创造GUI对象 */
        JButton jbtOK = new JButton("OK");

        JButton jbtCancel = new JButton("Cancel");

        JLabel jlblName = new JLabel("Enter your name: ");

        JTextField jtfName = new JTextField("Type Name Here");

        JCheckBox jchkBold = new JCheckBox("Bold");

        JCheckBox jchkItalic = new JCheckBox("Italic");

        JRadioButton jrbRed = new JRadioButton("Red");

        JRadioButton jrbYellow = new JRadioButton("Yellow");

        JComboBox jcboColor = new JComboBox(new String[]{"Freshmane",
            "Sophomore", "Junior", "Senior"});

        /* 创造面板对象 */
        JPanel panel = new JPanel();
        panel.add(jbtOK);
        panel.add(jbtCancel);
        panel.add(jlblName);
        panel.add(jtfName);
        panel.add(jchkBold);
        panel.add(jchkItalic);
        panel.add(jrbRed);
        panel.add(jrbYellow);
        panel.add(jcboColor);

        /* 创造框架 */
        JFrame frame = new JFrame();
        frame.add(panel);
        frame.setTitle("Show GUI Components");
        frame.setSize(450, 100);
        frame.setLocation(200, 100);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
