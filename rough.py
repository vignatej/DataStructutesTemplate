import requests
import time

url = "https://studentres.site/files/2658170315.pdf"

for i in range(100):  # try 100 times
    try:
        response = requests.get(url, timeout=10)
        if response.status_code == 200 and "application/pdf" in response.headers.get("Content-Type", ""):
            with open("sreehitha_results.pdf", "wb") as f:
                f.write(response.content)
            print("Downloaded successfully!")
            break
        else:
            print("Retrying...", response.status_code)
    except Exception as e:
        print("Error:", e)

    time.sleep(2)  # wait 2 seconds between attempts