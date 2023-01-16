/*
*******************************************
Objekt Info: Poti Drehknopf

*******************************************
Version: 16.01.2023 khf
*******************************************
*/

//***************   Auswahl   *************
// Form der Oberseite des Knopfes.  Der Typ "Einbau" kann lackiert werden.
CapType = 1;	// [0:Flach, 1:Einbau, 2:Dome]

// Möchtest du einen großen StilZeiger?
TimerKnob=0;	// [0:Nein, 1:Ja]

// Möchtest du eine Markierung oben, um die Richtung anzuzeigen?
Pointer1 = 0;	// [0:Nein, 1:Ja]

// Möchtest du einen Richtungszeiger?
Pointer2 = 0;	// [0:Nein, 1:Ja]

// Willst du einen Rändelung um den Knopf?
Knurled = 1;	// [0:Nein, 1:Ja]

//***************   Libraries  ************

//keine

//*****************************************

//***************  Parameter   *************
$fn=80;

// Loch-Durchmesser in mm.
HoleDiameter = 6.1;

// Tiefe des Lochs im Boden (in mm). 
HoleDepth = 18;

// Wenn du ein D-förmiges Loch wünscht, stelle die Dicke auf der flachen Seite (in mm) ein.  Größere Werte für die Ebene machen das Loch kleiner.
HoleFlatThickness = 0;

// Höhe (in mm).  Wenn die Kuppelkappe ausgewählt ist, ist sie nicht in der Höhe enthalten.  Auch die Wellenlänge wird nicht gezählt.
KnobHeight = 20;

// Durchmesser des Knopfes in mm.  
KnobDiameter = 15;

// 0 = Verjüngung
TaperPercentage = 20;		// [0:0%, 10:10%, 20:20%, 30:30%, 40:40%, 50:50%]

// Breite des Rings "Dial" (in mm).  0= keine RIng
RingWidth = 2;

// Die Anzahl der Markierungen auf dem Zifferblatt.  0 = keine Markierungen   (RingWidth muss ungleich Null sein.)
RingMarkings = 0;

// Durchmesser des Lochs für die Befestigungsschraube in mm.  0 = kein Loch
ScrewHoleDiameter = 0;

//  Länge der Welle auf der Unterseite des Knopfes (in mm).  0 = keine Welle
ShaftLength = 0;

// Durchmesser der Welle auf der Unterseite des Knopfes in mm.  (ShaftLength größer Null sein.)
ShaftDiameter = 10;

// Möchtest du eine Kerbe in der Welle?  Es kann für einen Einpressknopf verwendet werden (anstelle einer Befestigungsschraube).  (ShaftLength größer Null sein.)
NotchedShaft = 0;	// [0:No, 1:Yes]


//*****************************************

//**************   Programm  **************

//////////////////////////
//Erweiterte Einstellungen
//////////////////////////

RingThickness = 5*1;
DivotDepth = 1.5*1;
MarkingWidth = 1.5*1;
DistanceBetweenKnurls = 3*1;
TimerKnobConst = 1.8*1;

//////////////////////////
//Berechnungen
//////////////////////////

PI=3.14159265*1;
KnobMajorRadius = KnobDiameter/2;
KnobMinorRadius = KnobDiameter/2 * (1 - TaperPercentage/100);
KnobRadius = KnobMinorRadius + (KnobMajorRadius-KnobMinorRadius)/2;
KnobCircumference = PI*KnobDiameter;
Knurls = round(KnobCircumference/DistanceBetweenKnurls);
Divot=CapType;

TaperAngle=asin(KnobHeight / (sqrt(pow(KnobHeight, 2) +
		pow(KnobMajorRadius-KnobMinorRadius,2)))) - 90;

DivotRadius = KnobMinorRadius*.4;

difference() {
union()
{
translate([0, 0, (ShaftLength==0)? 0 : ShaftLength-0.001])
difference()
{
union()
{
	// Primary knob cylinder
	cylinder(h=KnobHeight, r1=KnobMajorRadius, r2=KnobMinorRadius,
			$fn=50);
	
	if (Knurled)
		for (i=[0 : Knurls-1])
			rotate([0, 0, i * (360/Knurls)])
				translate([KnobRadius, 0, KnobHeight/2])
					rotate([0, TaperAngle, 0]) rotate([0, 0, 45])
						cube([2, 2, KnobHeight+.001], center=true);

 	if (RingMarkings>0)
		for (i=[0 : RingMarkings-1])
			rotate([0, 0, i * (360/RingMarkings)])
				translate([KnobMajorRadius + RingWidth/2, 0, 1])
					cube([RingWidth*.5, MarkingWidth, 2], center=true);		
	
	if (Pointer2==1)
		translate([KnobRadius, 0, KnobHeight/2-2])
			rotate([0, TaperAngle, 0])
				cube([8, 3, KnobHeight], center=true);		

	if (RingWidth>0)
		translate([0, 0, RingThickness/2])
			cylinder(r1=KnobMajorRadius + RingWidth, r2=KnobMinorRadius,
					h=RingThickness, $fn=50, center=true);

	if (Divot==2)
		translate([0, 0, KnobHeight])
			difference()
			{
				scale([1, 1, 0.5])
					sphere(r=KnobMinorRadius, $fn=50, center=true);

				translate([0, 0, 0-(KnobMinorRadius+.001)])
					cube([KnobMinorRadius*2.5, KnobMinorRadius*2.5,
							KnobMinorRadius*2], center=true);
			}

	if (TimerKnob==1) intersection()
		{
			translate([0, 0, 0-(KnobDiameter*TimerKnobConst) + KnobHeight])
			sphere(r=KnobDiameter*TimerKnobConst, $fn=80, center=true);		
	
			translate([0-(KnobDiameter*TimerKnobConst)*0.1, 0,
					KnobHeight/2])
				scale([1, 0.5, 1])
					cylinder(h=KnobHeight, r=(KnobDiameter*TimerKnobConst) *
							0.8, $fn=3, center=true);
		}
}

// Zeiger1
if (Pointer1==1)
	translate([KnobMinorRadius*.55, 0, KnobHeight + DivotRadius*.6])
		sphere(r=DivotRadius, $fn=40);

// Divot1: Zentrierter zylynischer Divot
if (Divot==1)
	translate([0, 0, KnobHeight])
		cylinder(h=DivotDepth*2, r=KnobMinorRadius-1.5, $fn=50,
				center=true);

if (ShaftLength==0)
{
	// Loch für die Welle
	translate([0, 0, HoleDepth/2 - 0.001])
		difference()
		{
			cylinder(r=HoleDiameter/2, h=HoleDepth, $fn=20,
					center=true);
	
			// D-förmiges Loch
			translate([(0-HoleDiameter)+HoleFlatThickness, 0, 0])
				cube([HoleDiameter, HoleDiameter, HoleDepth+.001],
						center=true);
		}
	
	// Loch für die Befestigungsschraube
	if (ScrewHoleDiameter>0)
		translate([0 - (KnobMajorRadius+RingWidth+1)/2, 0,
				HoleDepth/2])
			rotate([0, 90, 0])
			cylinder(h=(KnobMajorRadius+RingWidth+1),
					r=ScrewHoleDiameter/2, $fn=20, center=true);
}

// Stelle sicher, dass die unteren Enden bei z=0 sind
translate([0, 0, -10])
	cube([(KnobMajorRadius+RingWidth) * 3,
			(KnobMajorRadius+RingWidth) * 3, 20], center=true);
}

if (ShaftLength>0)
	difference()
	{
		translate([0, 0, ShaftLength/2])
			cylinder(h=ShaftLength, r=ShaftDiameter/2, $fn=20,
					center=true);

		if (NotchedShaft==1)
		{
			cube([HoleDiameter/2, ShaftDiameter*2, ShaftLength],
					center=true);
		}

		// Loch für die Welle
		translate([0, 0, HoleDepth/2 - 0.001])
			difference()
			{
				cylinder(r=HoleDiameter/2, h=HoleDepth, $fn=20,
						center=true);
		
				// D-förmiges Loch
				translate([(0-HoleDiameter)+HoleFlatThickness, 0, 0])
					cube([HoleDiameter, HoleDiameter, HoleDepth+.001],
							center=true);
			}
		
		// Loch für die Befestigungsschraube
		if (ScrewHoleDiameter>0)
			translate([0 - (KnobMajorRadius+RingWidth+1)/2, 0,
					HoleDepth/2])
				rotate([0, 90, 0])
				cylinder(h=(KnobMajorRadius+RingWidth+1),
						r=ScrewHoleDiameter/2, $fn=20, center=true);
	}
}


translate(v = [0, 0, 1]) { 
cylinder(h = 5, r1 = 6, r2 = 6, center = true);
}
translate(v = [0, 0, 4]) { 
cylinder(h = 6, r1 = 3, r2 = 3, center = true);
    }
}
