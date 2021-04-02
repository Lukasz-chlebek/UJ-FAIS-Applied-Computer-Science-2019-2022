import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import javax.swing.*;

class GUI extends JPanel {
    private static final int WidthOfApp = 1200;
    private static final int HeightOfApp = 600;
    private static final long serialVersionUID = 1L;
    private final JButton Exit = new JButton("QUIT");
    private final JButton Forward = new JButton("FORWARD");
    private final JButton left = new JButton("LEFT");
    private final JButton right = new JButton("RIGHT");
    private final JButton up = new JButton("PEN UP");
    private final JButton down = new JButton("PEN DOWN");
    private final JButton clear = new JButton("CLEAN");
    private int angle = 0;
    private boolean isDrawing = false;
    private final  JTextField Coordinats;
    private final  JTextField Direction;
    private final  JTextField PenStatus;

    public GUI(){

        Coordinats = new JTextField("Koordynaty: (" + Turtle.start_x +", "+ Turtle.start_y +" )");
        Direction = new  JTextField("Kierunek: 0");
        PenStatus = new  JTextField("Status olowka: up");

        JPanel ToDrawPanel = new Turtle();
        JPanel BackgroundPanel = new JPanel();
        JPanel ButtonsPanel = new JPanel();
        JPanel TextPanel = new JPanel();

        ButtonsPanel.setBackground(Color.black);
        ButtonsPanel.setLayout(new GridLayout(7,1));
        ButtonsPanel.add(Forward);
        ButtonsPanel.add(left);
        ButtonsPanel.add(right);
        ButtonsPanel.add(up);
        ButtonsPanel.add(down);
        ButtonsPanel.add(clear);
        ButtonsPanel.add(Exit);
        up.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                    isDrawing = false;
                PenStatus.setText("Pen status: up");
            }
        });
        down.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                    isDrawing = true;
                PenStatus.setText("Pen status: down");
            }
        });
        left.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                angle -=90;
                Direction.setText("Direction: "+Math.abs(angle %360));
            }
        });

        right.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                angle +=90;
                Direction.setText("Direction: "+Math.abs(angle %360));
            }
        });

        Exit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        ToDrawPanel.setBackground(Color.white);
        ToDrawPanel.setOpaque(true);

        TextPanel.add(Coordinats);
        TextPanel.add(Direction);
        TextPanel.add(PenStatus);
        TextPanel.setBackground(Color.PINK);
        setOpaque(true);
        BackgroundPanel.setBackground(Color.white);
        setOpaque(true);
        BackgroundPanel.add(TextPanel);
        BackgroundPanel.add(ButtonsPanel);

        ButtonsPanel.setBackground(Color.darkGray);
        setOpaque(true);
        ToDrawPanel.setBackground(Color.WHITE);
        setOpaque(true);
        JFrame  Frame = new JFrame();
        Frame.setSize(new Dimension(WidthOfApp, HeightOfApp));
        Frame.setBackground(Color.green);
        setOpaque(true);
        Frame.setMaximumSize(new Dimension(WidthOfApp, HeightOfApp));
        Frame.setMinimumSize(new Dimension(WidthOfApp, HeightOfApp));
        Frame.setResizable(false);
        Frame.setLayout(new BorderLayout());
        Frame.add(ToDrawPanel,BorderLayout.CENTER);
        Frame.add(ButtonsPanel, BorderLayout.WEST);
        Frame.add(TextPanel, BorderLayout.SOUTH);
        Frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Frame.setTitle("Logo Turtle");
        Frame.pack();
        Frame.setVisible(true);

    }

    class Turtle extends JPanel{
        private static final long serialVersionUID = 1L;
        private static final int Width = 988;
        private static final int Height = 576;
        private static final int start_x = Width /2;
        private static final int start_y = Height /2;
        private int current_x = start_x;
        private int current_y = start_y;
        private ArrayList<Line> lines;

        public Turtle(){
            lines = new ArrayList<Line>(0);
            Forward.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    int tempY = current_y;
                    int tempX = current_x;
                    current_y -= 25 * Math.cos(Math.toRadians(angle));
                    current_x += 25 * Math.sin(Math.toRadians(angle));
                    if(isDrawing)
                        lines.add(new Line(current_x, current_y,tempX, tempY));

                    repaint();
                }
            });
            clear.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    lines.clear();
                    current_x = Width /2;
                    current_y = Height /2;
                    angle = 0;
                    Direction.setText("Direction: 0");
                    Coordinats.setText("Coordinats: ( "+ start_x +", "+ start_y +" )");
                    repaint();
                }
            });
        }
        public void Draw(Graphics g) {
            g.setColor(Color.black);
            for(int i = 0; i < lines.size(); ++i) {
                    g.drawLine(lines.get(i).x1, lines.get(i).y1, lines.get(i).x2, lines.get(i).y2);
            }
            Coordinats.setText("Coordinats: ( " + current_x + ", " + current_y + " )");
        }
        @Override
        public void paintComponent(Graphics g){
            super.paintComponent(g);
            Draw(g);
        }

    }

}
class Line {
    int x1;
    int x2;
    int y1;
    int y2;

    public Line(int x1, int y1, int x2, int y2) {
        this.x1 = x1;
        this.x2 = x2;
        this.y1 = y1;
        this.y2 = y2;
    }
}
 public class Turtle {
     public static void main(String[] args){
       GUI g= new GUI();
    }
}
