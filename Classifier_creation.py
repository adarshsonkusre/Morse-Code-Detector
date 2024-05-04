
import numpy as np
from glob import glob
from os.path import basename
from sklearn.ensemble import RandomForestClassifier
from micromlgen import port


def load_features(folder):
    dataset = None
    classmap = {}
    for class_idx, filename in enumerate(glob('%s/*.csv' % folder)):
        class_name = basename(filename)[:-4]
        classmap[class_idx] = class_name
        samples = np.loadtxt(filename, dtype=float, delimiter=',')
        labels = np.ones((len(samples), 1)) * class_idx
        samples = np.hstack((samples, labels))
        dataset = samples if dataset is None else np.vstack((dataset, samples))
    return dataset, classmap


if __name__ == '__main__':
    features, classmap = load_features('training_data')
    X, y = features[:, :-1], features[:, -1]
    classifier = RandomForestClassifier(20, max_depth=10).fit(X, y)
    c_code = port(classifier, classmap=classmap)
    print(c_code)
