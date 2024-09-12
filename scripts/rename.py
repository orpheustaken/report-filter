# definitely not used to rename torrents

import os, sys


def rename_files():

    directory = sys.argv[1]

    try:
        random_file = rename_algorithm(os.listdir(directory)[0])

        print("This is how one of the files will look like after renamed:")
        print(random_file)

        option = input("\nWould you like to continue? [Y/n]: ")

        if option == "Y":
            for filename in os.listdir(directory):

                if os.path.isfile(os.path.join(directory, filename)):
                    new_filename = rename_algorithm(filename)

                    print(new_filename)
                    os.rename(os.path.join(directory, filename), os.path.join(directory, new_filename))

            print("\nFiles have been renamed successfully.")

    except FileNotFoundError:
        print("The file was not found. Please check the file path and try again.")


# adjust the renaming algorithm based on the file pattern
def rename_algorithm(filename):
    new_filename = filename[31:]
    # new_filename = new_filename.replace(".", " ")
    new_filename = new_filename[:-37] + ".mkv"
    # new_filename = new_filename.replace(" ", " - ", 1)

    return new_filename


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Provide a path to the directory where the files to be renamed are at.")
        print("Usage: rename.py <path>")
        print("\nExample: rename.py \"/home/user/Torrents/How I Met Your Mother (2005)/Season 1\"")

        exit(1)

    rename_files()

