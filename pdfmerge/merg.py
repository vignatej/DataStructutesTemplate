from pypdf import PdfMerger
pdfs = []
for i in range(0, 5):
    pdfs.append("c"+str(i)+".pdf")
# print(pdfs)
merger = PdfMerger()

for pdf in pdfs:
    merger.append(open(pdf, 'rb'))

merger.write("Merged-Output.pdf")
merger.close()