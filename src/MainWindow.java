
import javax.swing.*;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;

public class MainWindow extends JFrame implements ActionListener {
	JButton button1 = null;
	JButton button2 = null;
	JButton button3 = null;
    private static final long serialVersionUID = 1L; 

	JTextArea text_area = null;
	JScrollPane scroll_bar = null;
	JMenuBar menu_bar = null;
	JToolBar tool_bar = null;
	
	JMenu menu1 = null;
	JMenu menu2 = null; 
	
	JMenuItem menuItem = null;
	JMenuItem menuItem2 = null;
	JMenuItem menuItem3 = null;
	JMenuItem menuItem4 = null;
	
	public static void main(String[] argv) {
		MainWindow window = new MainWindow();
	}
	
	public MainWindow() {
		menu_bar = new JMenuBar();
		tool_bar = new JToolBar();
		menu1 = new JMenu("Menu 1");
		add(menu1);
		menu2 = new JMenu("Menu 2");
		add(menu2);
		
		menuItem = new JMenuItem("I love INF224");
		menuItem.addActionListener(this);
		menuItem2 = new JMenuItem("Me gusta INF224");
		menuItem2.addActionListener(this);
		menuItem3 = new JMenuItem("I love INF224");
		menuItem3.addActionListener(this);
		menuItem4 = new JMenuItem("Me gusta INF224");
		menuItem4.addActionListener(this);
		
		menu1.add(menuItem);
		menu1.add(menuItem2);
		menu2.add(menuItem3);
		menu2.add(menuItem4);
		
		menu_bar.add(menu1);
		menu_bar.add(menu2);		
		add(tool_bar, BorderLayout.NORTH);
		setJMenuBar(menu_bar);

		
		
		text_area = new JTextArea(15, 30);
		add(text_area, BorderLayout.CENTER);
		button1 = new JButton("Quitter");
		add(button1, BorderLayout.PAGE_END);
		button2 = new JButton("I love INF224");
		add(button2, BorderLayout.WEST);
		button3 = new JButton("Me gusta INF224");
		add(button3, BorderLayout.EAST);
		
		button1.addActionListener(this);
		button2.addActionListener(this);
		button3.addActionListener(this);
		
		scroll_bar = new JScrollPane(text_area);
		add(scroll_bar);
		
		
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Set-Top Box multimedia");
		pack();
		setVisible(true);
	
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		
		
		if (e.getSource() == button1) {
			System.exit(0);
		}
		else if (e.getSource() == button2 || e.getSource() == menuItem || e.getSource() == menuItem3) {
			text_area.setText(text_area.getText() + "I love INF224\n");
		}
		else if (e.getSource() == button3 || e.getSource() == menuItem2 || e.getSource() == menuItem4) {
			text_area.setText(text_area.getText() + "Me gusta INF224\n");
		} 
		else {
			
		}
		pack();
	}
}

